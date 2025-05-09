function mergeArrays(arr1, arr2) {
  let mergedArray = arr1.concat(arr2);
  return mergedArray;
}

let arr1 = [1, 2, 3];
let arr2 = [4, 5];

let mergedArray = mergeArrays(arr1, arr2);

console.log("Merged Array:", mergedArray);
