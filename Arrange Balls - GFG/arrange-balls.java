//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            String s = br.readLine().trim();
            String[] S = s.split(" ");
            int p = Integer.parseInt(S[0]);
            int q = Integer.parseInt(S[1]);
            int r = Integer.parseInt(S[2]);
            Solution ob = new Solution();
            int ans = ob.CountWays(p, q, r);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution
{
   static int mod = 1000000007;
   static int dp[][][][] = new int[101][101][101][4];
   public int CountWays(int p, int q, int r)
   {
       // code here
       for(int arr[][][]:dp)
           for(int a[][]:arr)
               for(int b[]:a)
                   Arrays.fill(b,-1);
       return solve(p,q,r,3);
   }
   public int solve(int p,int q,int r,int prevball)
   {
       if(p+q+r==0)
           return 1;
       if(dp[p][q][r][prevball]!=-1)
           return dp[p][q][r][prevball];
       int noOfWays = 0;
       if(p>0 && prevball!=0)
           noOfWays = (noOfWays+solve(p-1,q,r,0)%mod)%mod;
       if(q>0 && prevball!=1)
           noOfWays = (noOfWays+solve(p,q-1,r,1)%mod)%mod;
       if(r>0 && prevball!=2)
           noOfWays = (noOfWays+solve(p,q,r-1,2)%mod)%mod;
           
       return dp[p][q][r][prevball] = noOfWays%mod;
   }
}