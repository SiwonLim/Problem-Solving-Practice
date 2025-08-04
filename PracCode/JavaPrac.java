package PracCode;
public class JavaPrac {
    public static void main(String[] args){
        int[] nums = {3,2,1,0,4};
        System.out.println(canJump(nums));
    }

    public int jump(int[] nums) {
        int jumps=0, current_end=0, farthest=0;
        for(int i = 0 ; i < nums.length-1 ; i++){
            farthest = Math.max(farthest, i+nums[i]);
            
            //제일 먼곳까지 점프했다면? ->
            //jump수 추가 ->
            //다시 제일 먼곳 까지 점프할 수 있는곳 지정 ->
            //반복
            if(i == current_end){
                jumps++;
                current_end = farthest;
            }
        }
        return jumps;
    }

    public static boolean canJump(int[] nums) {
        //1 가장 멀리 갈 수 있는 거리"를 계속 추적해봐.
        int max = 0;
        //2 배열을 앞에서부터 순회하면서,
        for(int i = 0 ; i < nums.length ; i++){
            //3 i는 뛰려는 곳, max는 뛸 수 있는 총 거리를 의미
            //내가 뛰려는곳이, 내가 최대로 뛸 수 있는 거리보다 멀다면? 끝까지 도달 못함
            if(i > max){
                return false;
            }
            //현재까지 최고거리 vs 현재 위치부터 index값을 더한 거리
            //=>현재 위치에서 더 멀리 갈 수 있는지 갱신
            max = Math.max(max, i+nums[i]);
        }
        //마지막까지 도달가능
        return true;  
    }
}
