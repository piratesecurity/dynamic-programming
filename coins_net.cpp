    #include<iostream>
    #include<cstdio>
    #include<algorithm>
    using namespace std;
    #define N 1000000
    long long arr[N];
    long long f(long long n)
    {
			printf("%lld\n",n);
            if(n<N)
            if(arr[n]!=0)
            return arr[n];
            if(n<5)
            return n;
            long long t=max( n, f(n/2)+f(n/3)+f(n/4) );
            if(n<N)
            arr[n]=t;
            return t;
    }
    int main()
    {
            long long  a,i;
            for(i=0;i<N;i++)
            {
                    arr[i]=0;
            }
            while(scanf("%lld",&a)!=EOF)
            {
                    printf("%lld\n",f(a));
            }
            return 0;
    }
