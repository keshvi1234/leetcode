class Solution {
public:
    int countElements(vector<int>& v, int k) {
        int n=v.size();
        long long cnt=0;
        sort(v.begin(),v.end());

        int i=0;
        while(i<n){
                int j=i;
                while(j< n && v[j]==v[i]){
                    j++;
                }
                if((n-j)>=k) cnt=cnt+(j-i);
                i=j;
        }





        return cnt;
    }
};