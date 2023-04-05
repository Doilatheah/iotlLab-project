// khoi tao cac thong so
let btn1 = document.querySelector('#btn1');
let img1 = document.querySelector('#gate');
let btn2 = document.querySelector('#btn2');
// functions nut bam
// const database=firebase.database();
// const deviceRef=database.ref('quan1');
btn1.addEventListener('click', ()=>{
    img1.src = 'slider/doorclose.gif'; 
    firebase.database().ref("device1").set({gate: 1})
})   
btn2.addEventListener('click', ()=>{
    img1.src = 'slider/wardrobe-removebg-preview.png';
    firebase.database().ref("device1").set({gate: 0})
})
let newWidth = 180;
let newHeight = 125;
img1.width = newWidth;
img1.height = newHeight;
// khoi tao cac thong so
let btn3 = document.querySelector('#btn3');
let img2 = document.querySelector('#led');
let btn4 = document.querySelector('#btn4');
// functions nut bam
btn3.addEventListener('click', ()=>{
    img2.src = 'slider/denon1.gif'; 
    firebase.database().ref("device2").set({light:1})
})

btn4.addEventListener('click', ()=>{
    img2.src = 'slider/den1.png';
    firebase.database().ref("device2").set({light:0})
})
img2.width = 170;
img2.height = 125;


// khoi tao cac thong so
let btn5 = document.querySelector('#btn5');
let img3 = document.querySelector('#siren');
let btn6 = document.querySelector('#btn6');

btn5.addEventListener('click', ()=>{
    img3.src = 'slider/DelayedVacantDassie-max-1mb.gif' ;
    firebase.database().ref("device3").set({siren:1})

})
btn6.addEventListener('click', ()=>{
   img3.src = 'slider/zyro-image.png';
   firebase.database().ref("device3").set({siren: 0})

})
img3.width = newWidth;
img3.height = newHeight;


