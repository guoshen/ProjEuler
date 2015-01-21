/**Problem 31:In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:

1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
It is possible to make £2 in the following way:

1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
How many different ways can £2 be made using any number of coins?

Solved By: Shengyuan Guo in 2013


IDEA:Use Top Down Approach. Try to use the largest coins to make 200p and then gradually
use smaller coins.
Dynamic Programming:


D[200, {200,100,25,10,5,1}]= D[200, {100,50,20,5,2,1}]+D[0,{100,50,20,5,2,1}];

Number of ways to make 200p using {200,100,25,10,5,1} coins is the sum of:
the number of ways to make 200p using {100,50,20,5,2,1} coins using 0 200p coins
and the number of ways to make 200p using {100,50,20,5,2,1} coins using 1 200p coin

Countinue  recursive pattern until base case(s):
D[200,{1}]=1;

 **/


#include <iostream>


using namespace std;

int makeCurr(int amount, int coins[],int numCoins);

int main()
{
	// eight types of coins
	int coins[8]={200,100,50,20,10,5,2,1};

	cout<<"Number of ways to make 200p:"<<makeCurr(200, coins,8);



}

int makeCurrHelper(int amount, int coins[], int numCoins, int currCoin)
{

    if(amount==0)
        return 0;
        // currCoin is last coin in coins arr
	if(currCoin==numCoins-1)
	{
	    // remaining amount can be made using only the last coin in arr
	    if(amount%coins[currCoin]==0)
	    return 1;
        else
        return 0;

	}


        int count=0;

        int i;
        if (amount%coins[currCoin]==0)
            count++;

        for(i=0;i*coins[currCoin]<amount;i++)
        {
            count+=makeCurrHelper(amount-i*coins[currCoin],coins,numCoins,currCoin+1);
        }
        return count;


}

//returns the number of ways to make amount using the denominations of coins array
//assume coins array is sorted from greatest to least
int makeCurr(int amount, int coins[],int numCoins)
{

	int currCoin=0;

	return makeCurrHelper(amount,coins,numCoins,currCoin);


}


