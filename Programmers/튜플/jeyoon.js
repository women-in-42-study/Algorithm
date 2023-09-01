function solution(s) {
  let answer = [];
  const arr = s
    .replace("{{", "")
    .replace("}}", "")
    .split("},{")
    .map((set) => set.split(",").map((num) => Number(num)));
  arr.sort((arrA, arrB) => arrA.length - arrB.length);
  // console.log(arr); 	//[ [ 2 ], [ 2, 1 ], [ 2, 1, 3 ], [ 2, 1, 3, 4 ] ]

  // 방법 1: 직접 중복을 제거하고 answer에 넣기
  // arr.forEach((subset) => subset.forEach((num) => {
  //     if (!answer.includes(num)) answer.push(num);
  // }));

  // 방법 2: Set을 이용하여 중복을 제거하고 answer에 넣기
  const tuple = new Set();
  arr.forEach((subset) => subset.forEach((num) => tuple.add(num)));
  answer = [...tuple];

  return answer;
}
