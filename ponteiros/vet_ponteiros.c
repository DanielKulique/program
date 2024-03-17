void main()
{
    int v[2]={2,3};
    int *a = v;
    *(a+1)=2;//v[1]=2;
    printf("\nv1: %d", v[1]);
    

}
