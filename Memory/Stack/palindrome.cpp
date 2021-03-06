/**
 * @date 2018-04-26
 * @brief Determines whether a string is a palindrome.
 * @note There is a little question:In line 22, you should use ++top, but can't use top++, why?
 */

#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int main(){
    char a[101]={0}, s[101]={0};
    cin>>a;              ///cin a string
    int i, len , mid , next, top;

    len = strlen(a);     ///the length of the string
    mid = len/2 - 1;     ///the midpoint of the string


    top = 0;             ///Stack initialization
    for (int j = 0; j <= mid ; ++j) {       ///All characters before midpoint are in the stack.
        s[++top] = a[j];          ///!!!you need to add top first for it will And then it is going to go down to 0 to judge
    }                             

    if(len % 2 == 0){             ///Determine whether the length of the string is odd or even, and find the inspiration index that requires character matching.
        next = mid + 1;
    }
    else {
        next = mid + 2;
    }

    for( i = next; i <= len - 1; ++i){     ///Begin to match
        if(a[i] != s[top--]){
            break;
        }
    }

    if(top == 0) cout<<"YES, It's a palindrome"<<endl;    ///if top == 0 , then  it's all matched.
    else cout<<"No"<<endl;
   
    return 0;
}

Input:
2332
Output:
YES, It's a palindrome
