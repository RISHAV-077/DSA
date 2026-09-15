class Solution {
public:
    // 1️⃣ Find peak index
    int findPeak(MountainArray &arr) {
        int low = 1;
        int high = arr.length() - 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int midVal = arr.get(mid);
            int left = arr.get(mid - 1);
            int right = arr.get(mid + 1);

            if (midVal > left && midVal > right)
                return mid;
            else if (midVal < right)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }

    int binarySearch(MountainArray &arr, int target, int low, int high) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int val = arr.get(mid);

            if (val == target) return mid;
            else if (val < target) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
    int reverseBinarySearch(MountainArray &arr, int target, int low, int high) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int val = arr.get(mid);

            if (val == target) return mid;
            else if (val > target) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }

  
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        int peak = findPeak(mountainArr);
        int idx = binarySearch(mountainArr, target, 0, peak);
        if (idx != -1) return idx;

        return reverseBinarySearch(mountainArr, target, peak + 1, n - 1);
    }
};