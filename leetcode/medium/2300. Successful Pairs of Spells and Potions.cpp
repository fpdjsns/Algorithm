/**
 * problem : 
 * time comlexity : O(NlogN)
 */

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

        int n = spells.size(); 
        int m = potions.size();

        vector<pair<int,int>> spellsWithIndex(n);
        for(int i=0; i<n; i++)
            spellsWithIndex[i] = {spells[i], i};

        sort(spellsWithIndex.begin(), spellsWithIndex.end());
        sort(potions.begin(), potions.end());

        int potionInd = m-1;
        vector<int> answer(n);

        for(auto spell : spellsWithIndex) {
            while(potionInd >= 0 && ((potions[potionInd] * (long)spell.first) >= success))
                potionInd--;
            answer[spell.second] = m - (potionInd + 1);
        }
        
        return answer;
    }
};
