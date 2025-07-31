[Problem]<br>
https://leetcode.com/problems/jump-game/description

```java
public static boolean canJump(int[] nums) {
        //1 가장 멀리 갈 수 있는 거리"를 계속 추적
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
```

```python
def canJump(self, nums: List[int]) -> bool:
        maxJump=0
        for i in range(len(nums)):
            if i > maxJump:
                return False
            maxJump = max(maxJump, i+nums[i])
        return True
```