import java.util.*;
class Main {
    public static void main(String[] args) {
        System.out.println("Start small. Ship something.");
        Scanner s=new Scanner(System.in);
        String s1=s.nextLine();
        String s2=s.nextLine();
        int dp[][]=new int[s1.length()+1][s2.length()+1];
        for(int i=1;i<=s1.length();i++){
            for(int j=1;j<=s2.length();j++){
                if(s1.charAt(i-1)==s2.charAt(j-1)){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        int max=dp[0][0];
        for(int i=0;i<dp.length;i++){
            for(int j=0;j<dp[0].length;j++){
                if(dp[i][j]>=max){
                    max=dp[i][j];
                }
            }
        }
        System.out.println(max);
    }
}
