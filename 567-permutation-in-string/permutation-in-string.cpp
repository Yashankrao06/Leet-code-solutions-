class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        // Agar s1 s2 se bada hai, to permutation hona impossible hai
        if (n1 > n2) return false;

        // Step 1: s1 ko ek baar sort kar lo (Target string)
        string target = s1;
        sort(target.begin(), target.end());

        // Step 2: s2 ke andar n1 size ki window slide karo
        for (int i = 0; i <= n2 - n1; i++) {
            // Window ka substring extract karo
            string temp = s2.substr(i, n1);

            // Substring ko sort karo
            sort(temp.begin(), temp.end());

            // Agar dono sorted strings match ho jayein, matlab permutation mil gaya
            if (temp == target) {
                return true;
            }
        }

        return false;
    }
};