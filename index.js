let boxes=document.querySelectorAll(".btn");
let res=document.querySelector("#rst-btn");
let msg=document.querySelector("h1");
let msgbox=document.querySelector(".msg");
let mainbox=document.querySelector(".mainbox");
// console.log(res);
// console.log(boxes);

let turnO=true;

const winpatterns=[
    [0,1,2],
    [0,3,6],
    [0,4,8],
    [1,4,7],
    [2,5,8],
    [2,4,6],
    [3,4,5],
    [6,7,8]
];
const checkwinner=()=>{
    for(let pattern of winpatterns){
        // console.log(pattern);
        let a=boxes[pattern[0]].innerText;
        let b=boxes[pattern[1]].innerText;
        let c=boxes[pattern[2]].innerText;
        if(a!="" && b!="" && c!=""){
           if(a==b && b==c){ 
            msg.innerText=`winner ${a}`;
            msgbox.classList.remove("hide");
            mainbox.classList.add("win");

           }
        }
    }
}
let newgame=document.querySelector(".new-game");
newgame.addEventListener("click",()=>{
    // console.log(newgame);
    // console.log("new game");
    msgbox.classList.add("hide");
    mainbox.classList.remove("win");
    msg.innerText="";
    for(let box of boxes){
        // console.log(box);
        box.disabled=false;
        box.innerText="";
        turnO=true;
    }
})
 


for( let box of boxes){
    box.addEventListener("click",()=>{
        if(turnO){
            box.innerText="O";
            turnO=false;
        }else{
            turnO=true;
            box.innerText="X";
        }
      
        box.disabled=true;
        checkwinner();
    });
}

res.addEventListener("click",()=>{
    for(let box of boxes){
        // console.log(box);
        box.disabled=false;
        box.innerText="";
    }
})