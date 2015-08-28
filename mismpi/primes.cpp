int prime[500]; // prime[i]==0 means i is prime

template<int n> void fillMultiple(int i)
{
    prime[n*i]=1; // n is prime, mark all its multiples as non-prime
    n*i<500?fillMultiple<n>(i+1):fillMultiple<499>(i);
}

template<> void fillMultiple<499>(int i)
{
     // do nothing
     // only used as dummy function
}

template<int n> void generatePrime()
{       
    prime[n]==0?fillMultiple<n>(2):generatePrime<n+1>(); //if n is prime,mark all the multiples of n as non-prime.
    generatePrime<n+1>();
}

template<> void generatePrime<499>()
{
     // do nothing
     // only used as dummy function
}

int main()
{
    prime[0]=prime[1]=1; // 0 and 1 is non-prime
    generatePrime<2>();

    for(int i=0;i<500;i++) // print prime numbers
            if(0==prime[i]) // if prime[i]==0, then i is prime
                    cout<<i<<endl;

    return 0;
}