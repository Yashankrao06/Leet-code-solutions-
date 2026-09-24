class Solution {
public:
/* ek stack banao empty aur ek vector jisko return karenge 
pehe iterate kro atreroid array me left to right aur usko dalao stack (ek ke kr ke har iteration me ek element) me fir iterate kr ke next element pe jao check kro ki kahi top element aur current element either both +ve or -ve (both of them) if not then check which is smaller top or the current element or they are equal pop the smaller one and put the larger element on the stack top nad move to next elemnt continung the loop if equal pop the top nad instert the current element 


Ek stack initialize karo.Asteroids array par left to right iterate karo.   Har asteroid ke liye ek while loop chalao jiska condition ho: stack empty nahi hai AND stack ka top > 0 hai AND current element < 0 hai.Is while loop ke andar dono ke sizes ko absolute values abs() se compare karo:Agar stack.top() < abs(current): Stack wala asteroid chota hai aur explode hoga. Ise pop kardo. (Loop continue rahega taaki current asteroid stack ke aur peeche wale elements se takra sake).Agar stack.top() == abs(current): Dono explode honge. Stack ke top ko pop kardo aur current element ko "destroyed" mark karke while loop ko break kardo.   Agar stack.top() > abs(current): Current asteroid chota hai aur explode ho jayega. Current ko "destroyed" mark karo aur loop ko break kardo.   Agar loop khatam hone ke baad current asteroid destroy nahi hua hai, tabhi usko stack mein push karo.Aakhri mein stack ke saare bache hue elements ek vector mein daal kar, unhe sahi order (reverse) mein arrange karke return kardo. 

*/
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for (int ast : asteroids) {
            bool destroyed = false;
            while (!st.empty() && st.back() > 0 && ast < 0) {
                if (st.back() < -ast) {
                    st.pop_back();
                    continue;
                } else if (st.back() == -ast) {
                    st.pop_back();
                }
                destroyed = true;
                break;
            }
            if (!destroyed) {
                st.push_back(ast);
            }
        }
        return st;
    }
};