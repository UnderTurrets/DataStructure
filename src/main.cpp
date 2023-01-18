#include <DataStructure.h>
int main(){

 vector<int>v1=   BubbleSort<int>({5,1,2,25,});
 v1.push_back(9);
 v1= BubbleSort(v1);
for(auto x:v1){
    cout<<x<<endl;
}


















    return 0;
}