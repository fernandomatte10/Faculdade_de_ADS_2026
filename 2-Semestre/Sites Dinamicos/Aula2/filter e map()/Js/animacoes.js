//let n = Number(prompt("Digite um numérico: "));
//console.log(n+10);
//alert(n+10);

//let n = [1, 2, 3, 4, 5, 6, 7, 8, 9];
//let v= n.filter(function (vetor) {
    //return vetor > 5;
//});
//alert(v);
//console.log(v);

let n = [1, 2, 3, 4, 5, 6, 7, 8, 9];
let v= n.map(function (vetor) {
return vetor * 5;
});
alert(v);
console.log(v);