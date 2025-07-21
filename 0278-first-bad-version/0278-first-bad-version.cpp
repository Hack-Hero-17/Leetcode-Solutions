// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // // 01 approach - linear search from start - TLE - o(n)
        // for (int i = 1; i <= n; i++) {
        //     // checking from start bc first bad version present on starting
        //     if (isBadVersion(i)) {
        //         return i;
        //     }
        // }

        // // not found
        // return -1;


        // 02 approach - bs - o(logn)
        int s = 1;
        int e = n;
        int mid;
        int firstBadVersion = -1;

        while (s <= e) {
            mid = s + ((e-s)>>1);

            // check if mid is bad version
            if (isBadVersion(mid)) {
                // may be this is firstBadVersion, save it
                firstBadVersion = mid;
                // try to minimize
                e = mid-1;
            }
            // not bad version means ans is at right side
            else {
                s = mid+1;
            }
        }

        return firstBadVersion;
    }
};