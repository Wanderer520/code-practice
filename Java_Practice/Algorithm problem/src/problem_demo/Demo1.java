package problem_demo;

public class Demo1 {
    public int uniqueXorTriplets(int[] nums) {
        if(nums.length<3)
            return nums.length;
        int ans = 1;
        while(ans <= nums.length)
            ans <<=1;
        return ans;
    }
}
