# PV 操作应用题

## 信号量限制并行数

> P97【2013统考】8.

```C++
cobegin
	semaphore gate = 1;		//出入口，仅允许一个人通过
	semaphore museum = 500;	//博物馆最多容纳人数
	
	参观者进程 i :
	{
		P(museum);
		P(gate);
		进门;
		V(gate);
		参观;
		P(gate);
		出门;
		V(gate);
		V(museum);
	}
coend
```

## 生产者-消费者

> P97 9. 生产车间

```C++
cobegin
	semaphore FULL1 = 10;
	semaphore FULL2 = 10;
	semaphore EMP1 = 0;
	semaphore EMP2 = 0;
	semaphore mutex1 = 1;
	semaphore mutex2 = 1;
	
	生产A :
	{
		生产一个A;
		P(FULL1);	//判空
		P(mutex1);
		把A放F1上;
		V(mutex1);
		V(EMP1);	//占F1一个位置
	}
	
	生产B :
	{
		生产一个B;
		P(FULL2);	
		P(mutex2);
		把B放F2上;
		V(mutex2);
		V(EMP2);
	}
	
	组装C :
	{
		P(EMP1);
		P(mutex1);
		拿A;
		V(mutex1);
		V(FULL1);
		
		P(EMP2);	//有B吗
		P(mutex2);
		拿B;		
		V(mutex2);
		V(FULL2);
		
		组装;
		
	}
coend	
```

> 