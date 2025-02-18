1. **sumRange Bug (Off-by-one error)**
  - The range is off by one, as stated in Seward's comment. ```end``` needs to be included in the sum
  - Fix: Change ```i < end``` to ```i <= end```.
2. **containsNegative Bugs**
  - Seward's comments denote 2 bugs here
  - ```i <= numbers.size()``` causes an out-of-bounds access since ```numbers.size()``` is the index of the last element, and we should be accessing elements only up to ```numbers.size() - 1```
  - The logic inside the loop is wrong. It checks if ```numbers[i] > 0``` (i.e., if a number is positive), but the function name ```containsNegative``` suggests that it should return ```true``` if the number is negative, not positive.
  - Fixes: Change the loop condition to ```i < numbers.size()``` and change the condition inside the loop to ```numbers[i] < 0```.
3. **findMax Bugs**
  - Seward's comments denote 3 bugs in this function    
  - ```if (numbers.empty()) return 0;``` is a really bad way to handle an empty array, it would be a lot better to throw an exception, since 0 could be a valid element of the array.
  - The loop condition ```i <= numbers.size()``` causes out-of-bounds access. 
  - ```numbers[i] >= maxVal``` is incorrect because ```findMax``` should be looking for the maximum value, and there are cases where the given comparasin is not appropriate for finding the maximum value.
  - Fixes: Throw an exception for the empty array, change ``` i <= numbers.size()``` to ```i < numbers.size()```, and change ```numbers[i] >= maxVal``` to ```numbers[i] > maxVal``` to update ```maxVal``` only when a larger value is found.
