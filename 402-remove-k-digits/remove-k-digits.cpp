class Solution {
public:
    string removeKdigits(string num, int k) {

        string st;  // String ko stack ki tarah use karenge

        // Har digit ko left → right process karo
        for (char digit : num) {

            // Previous digit bada hai → remove karo
            while (!st.empty() && k > 0 && st.back() > digit) {

                st.pop_back();  // Last digit remove
                k--;             // Ek removal use
            }

            // Current digit add karo
            st.push_back(digit);
        }

        // Agar k abhi bhi bacha hai,
        // toh end se digits remove karo
        while (k > 0) {

            st.pop_back();
            k--;
        }

        // Leading zeros remove karo
        int i = 0;

        while (i < st.size() && st[i] == '0') {
            i++;
        }

        // Agar sirf zeros bache hain
        if (i == st.size())
            return "0";

        // Final answer
        return st.substr(i);
    }
};