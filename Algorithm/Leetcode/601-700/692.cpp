class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>hashMap;
        vector<string>result;

        for(string &s : words)
        {
            hashMap[s]+=1;
        }

        for(auto &[s,count]:hashMap)
        {
            result.emplace_back(s);
        }

        sort(result.begin(),result.end(),[&](const string &s1,const string &s2){
            return hashMap[s1]==hashMap[s2]?s1<s2:hashMap[s1]>hashMap[s2];
        });

        result.erase(result.begin()+k,result.end());

        return result;
    }
};
