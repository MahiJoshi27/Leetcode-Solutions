class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maximum=0;
        int altitude=0;
        int n=gain.size();
        for(int i=0 ; i<n ; i++){
            altitude = altitude + gain[i];
            maximum=max(altitude , maximum);
        }
        return maximum;
        
    }
};