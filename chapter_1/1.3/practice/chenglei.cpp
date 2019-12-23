#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <set>
#include <string>
using namespace std;
int k;	// 设为全局变量，避免传参
int i_global;
set<long long>* *ppX;


// 并行算法第一步线程所使用的处理函数
void* exact_subset_sum_1(void *thread_arg)
{
	set<long long> *pS = (set<long long>*)thread_arg;
	set<long long> *pL = (set<long long>*)malloc( 1*sizeof(set<long long>) );
	set<long long> temp_s;
	set<long long>::iterator S_iter, L_iter, temp_iter;
	long long temp;
	S_iter = (*pS).begin();
	while( S_iter!=pS->end() )
    {
		if( *S_iter==k )
        {	//如果存在一个元素等于k，则直接返回
			printf("*S_iter = %lld\n", *S_iter);
			// 打印时间
			printf("spend time xx \n");
			exit(0);
		}
		temp_s.clear();	// 清空临时集合变量的元素
		temp_s.insert( *S_iter );	// 即与空集做笛卡尔积情况
		L_iter = pL->begin();
		while( L_iter!= pL->end() )
        {
			if( temp=(*L_iter + *S_iter),temp!=k )
            {
				temp_s.insert( temp );
			}
            else
            {
				printf("*L_iter=%lld, *S_iter=%lld\n", *L_iter,*S_iter);
				// 打印时间
				printf("spend time xx \n");
				exit(0);
			}
		}
		temp_iter = temp_s.begin();
		while( temp_iter!=temp_s.end() )
        {
			pL->insert( *temp_iter );
		}
	}
	pthread_exit( (void*)pL );	// 返回子集和的集合
}

// 并行算法第二步所需的线程处理函数
// void* (*exact_subset_sum_2)(void *thread_arg)
void* exact_subset_sum_2(void *thread_arg)
{
	set<long long> *pY = (set<long long>*)thread_arg;
	set<long long> *pTemp = (set<long long>*)malloc( 1*sizeof(set<long long>) );
	set<long long>::iterator X_iter, Y_iter;
	long long temp;
	Y_iter = pY->begin();
	while ( Y_iter!=pY->end() )
    {
		pTemp->insert( *Y_iter );
		X_iter = ppX[i_global]->begin();
		while ( X_iter!=ppX[i_global]->end() )
        {
			pTemp->insert( *X_iter );
			if( temp=*Y_iter+*X_iter, temp!=k )
            {
				pTemp->insert( temp );
			}
            else
            {
				printf("*Y_iter=%lld, *X_iter=%lld\n", *Y_iter,*X_iter);
				// 打印时间
				printf("spend time xx \n");
				exit(0);
			}
		}	
	}
	pthread_exit( (void*)pTemp );
}



int main(int argc, char **argv)
{
	if(argc != 4)
    {
		printf("need three arguments.\n");
		return 0;
	}
    cout << "-----------\n";
	int N = stoi(argv[1]);
	k = stoi(argv[2]);
	int n_thread = stoi(argv[3]);
	printf("N=%d, k=%d, n_thread=%d\n", N, k, n_thread);
	// 产生所需的 N 大小集合 S
	set<long long> S;
	long long temp;
	srand(time(NULL));
	for(int i=0; i<N; i++)
    {
		temp=rand()%100000000;
		S.insert( temp );
		//printf("temp = %lld\n", temp);
		//printf("S.begin() = %lld\n", *S.begin());
	}
	// 分成 n_thread 个互不相交的子集
	set<long long> *pSubset = (set<long long>*)malloc(n_thread*sizeof(set<long long>));
	int step_size = N/n_thread;
	set<long long>::iterator S_iter = S.begin();
	for(int i=0; i<n_thread; i++)
    {
		if( i != n_thread-1 )
        {
			for(int j=0; j<step_size; j++,S_iter++)
				pSubset[i].insert(*S_iter);
		}
        else
        {
			for( ; S_iter!=S.end(); S_iter++)
				pSubset[i].insert(*S_iter);
		}
	}
	// 生成 n_thread 个线程，并分别执行计算
	pthread_t *pthidArr = (pthread_t*)malloc(n_thread*sizeof(pthread_t));
	for(int i=0; i<n_thread; i++)
    {
		pthread_create(pthidArr+i, NULL, exact_subset_sum_1, pSubset+i);
	}
	// 汇合各个分段的子集和的集合
	ppX = (set<long long>**)malloc( n_thread*sizeof(set<long long>*) );
	for(int i=0; i<n_thread; i++)
    {
		pthread_join(pthidArr[i], (void**)&ppX[i]);
	}
	/* 进入并行算第二步 */
	set<long long>::iterator iter;
	set<long long> *pY = ppX[0];
	for(i_global=1; i_global<n_thread; i_global++)
    {
		// 将 Y 的集合分为 n_thread 个段
		for(int j=0; j<n_thread; j++)
        {
			pSubset[j].clear();
		}
		step_size = pY->size()/n_thread;
		iter = pY->begin();
		for(int j=0; j<n_thread; j++)
        {
			if( j != n_thread-1 )
            {
				for(int k=0; k<step_size; k++,iter++)
					pSubset[j].insert(*iter);
			}
            else
            {
				for( ; iter!=pY->end(); iter++)
					pSubset[j].insert(*iter);
			}
		}
		// 将分段后的集合分别分给线程做计算
		for(int j=0; j<n_thread; j++)
        {
			pthread_create(pthidArr+j, NULL, exact_subset_sum_2, pSubset+j);
		}
		// 回收每个线程结果
		set<long long> *p;
		for(int j=0; j<n_thread; j++)
        {
			pthread_join(pthidArr[j], (void**)&p);
			for(set<long long>::iterator it=p->begin(); it!=p->end(); it++)
				pY->insert( *it );
			free( p );	// p 指针由子线程申请的堆空间
		}
	}
	
	free(pSubset);
	free(pthidArr);
	free(ppX);
	return 0;
}
