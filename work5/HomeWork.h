#ifndef HomeWork
#define HomeWork
#define N 5


namespace lesson{
    void exercise2 (int massiv2[])
{
    for(int i=0; i<8; i++){
        if(i==0){
            massiv2[0]=1;
            continue;
        }
        massiv2[i]=massiv2[i-1]+3;
    }
}


void exercise3 (int checkBalance[])
{
    int counter=0, leftSum, rightSum;

    for(int i=0; i<N; i++){
        leftSum=0;
        rightSum=0;

        for(int j=0; j<=i; j++)
            leftSum+=checkBalance[j];

        for(int k=i+1; k<N; k++)
            rightSum+=checkBalance[k];

        if(leftSum == rightSum)
            ++counter;
    }
    (counter>0) ? std::cout << "true\n\n\n" : std::cout << "false\n\n\n";
}

void exercise4 (int arr[], int &n)
{
    int counter, temp;

    if(n>0){
    for(counter=0; counter < n; counter++){
        temp=arr[N-1];

        for(int i=N-1; i>0; i--){
            arr[i]=arr[i-1];
        }
        arr[0]=temp;
    }
    }

    else{
        for(counter=0; counter > n; counter--){
            temp=arr[0];

            for(int i=0; i<N-1; i++){
                arr[i]=arr[i+1];
            }
            arr[N-1]=temp;
        }
    }

    for(counter=0; counter < N; counter++)
        std::cout << arr[counter] << ' ';
}


}


#endif // HomeWork
