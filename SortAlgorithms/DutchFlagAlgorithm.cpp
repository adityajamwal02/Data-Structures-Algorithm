/// Dutch Flag Algorithm

/*
Idea to sort 0,1,2 (3 pointers) in minimum time (O(n))
maintain low, mid and high pointers initially considering the assumption
that behind low pointer there is sorted array of 0. Similarly, after high pointer
there is sorted array of 2. Mid pointer checks for 1, moves forward after swapping with
respective 0 or 2 pointer
*/

void DutchFlagAlgo(vector<int> &nums){
    int low=0;
    int mid=0;
    int high=nums.size();
    while(mid<=high){
        switch(nums[mid]){
        case 0:
            swap(nums[low++], nums[mid++]);
            break;

        case 1:
            mid++;
            break;

        case 2:
            swap(nums[high--], nums[mid]);
            break;
        }
    }
}


