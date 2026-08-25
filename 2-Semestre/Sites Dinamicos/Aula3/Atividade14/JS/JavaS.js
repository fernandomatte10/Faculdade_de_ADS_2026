let vetorN = [0,1,2,3,4,6,8,10,12,14,16,18,20];

for(let i=0 ; i < vetorN.length; i++){
    //alert(`${vetorN[i]}`);
    console.log(`${vetorN[i]}`);
}

let vetor1 = vetorN.filter(function (vetor) {
    return vetor > 10 || vetor < 2;
});

alert(vetor1);