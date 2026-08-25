class Solution {
public:
    int maximumSwap(int num) {
        vector<int> store;
        while (num != 0) {
            int ld = num % 10;
            store.push_back(ld);
            num /= 10;
        }
        reverse(store.begin(), store.end());
        vector<int> temp = store;
        sort(temp.begin(), temp.end());

        int idx = 0, j = store.size() - 1;
        while (idx < store.size() && store[idx] == temp[j]) {
            idx++;
            j--;
        }

        if(idx == store.size()){
            int ans = 0;
            for(int x : store){
                ans = ans * 10 + x;
            }
            return ans;
        }

        int keep = -1, track = store[idx];
        for (int i = idx + 1; i < store.size(); i++) {
            if (store[i] >= track) {
                track = store[i];
                keep = i;
            }
        }
        if (keep != -1) {
            swap(store[keep], store[idx]);
        }
        
        int ans = 0;
        for (int i = 0; i < store.size(); i++) {
            ans = (ans * 10) + store[i];
        }
        return ans;
    }
};