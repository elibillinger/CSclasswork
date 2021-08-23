// Author: Eli Billinger
public class CodingBatIndividual {
	// Array 2 -> tenRun
	public int[] tenRun(int[] nums) {
		boolean ten = false;
		int temp = 0;
		for(int i=0; i < nums.length; i++){
			if( nums[i] % 10 == 0 ){
				temp = nums[i];
				ten = true;
			} else if (ten && nums[i] % 10 != 0){
				nums[i] = temp;
			}
		}
		return nums;
	}
	/*
	 Expected This Run
	 tenRun([2, 10, 3, 4, 20, 5]) → [2, 10, 10, 10, 20, 20] OK
	 tenRun([10, 1, 20, 2]) → [10, 10, 20, 20] OK
	 tenRun([10, 1, 9, 20]) → [10, 10, 10, 20] OK
	 */

	//AP 1 -> scoresIncreasing
	public boolean scoresIncreasing(int[] scores) {
		boolean increasing = false;
		for(int i = 0; i < scores.length-1; i++){
			if(scores[i] == scores[i+1] || scores[i] < scores[i+1]){
				increasing = true;
			} else if(scores[i] > scores[i+1] ) {
				increasing = false;
				break;
			}
		}
		return increasing;
	}
	/*
	 Expected This Run
	 scoresIncreasing([1, 3, 4]) → true OK
	 scoresIncreasing([1, 3, 2]) → false OK
	 scoresIncreasing([1, 1, 4]) → true OK
	 scoresIncreasing([1, 1, 2, 4, 3, 7]) → false OK
	 */

	// String 2 -> repeatEnd
	public String repeatEnd(String str, int n) {
		String end = str.substring(str.length()-n,str.length());
		String newString = "";
		for(int i = 0; i < n; i++){
			newString += end;
		}
		return newString;
	}
	/*
	 Expected This Run
	 repeatEnd("Hello", 3) → "llollollo" OK
	 repeatEnd("Hello", 2) → "lolo" OK
	 repeatEnd("Hello", 1) → "o" OK
	 */

	// Array 3 -> canBalance
	public boolean canBalance(int[] nums) {
		int left = 0;
		int right = 0;
		boolean balance = false;
		for(int i: nums){
			right += i;
		}
		for( int i = 0; i < nums.length; i++){
			left += nums[i];
			right -= nums[i];
			if(left == right){
				balance = true;
			}
		}
		return balance;
	}
	/*
	 Expected This Run
	 canBalance([1, 1, 1, 2, 1]) → true OK
	 canBalance([2, 1, 1, 2, 1]) → false OK
	 canBalance([1, 2, 3, 1, 0, 1, 3]) → false OK
	 */
}
