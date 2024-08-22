let arr = [10, 20, 20, 10, 10, 20, 5, 20]
let frequency = {}
for(let i = 0; i < arr.length; i++){
    let count = arr[i];
    if(frequency[count] == undefined){
        frequency[count] = 1;
    }
    else{
        frequency[count]++;
    }
}
console.log(frequency)