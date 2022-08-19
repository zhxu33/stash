console.log('javascript is rad')

var number = 5;
var string = 'Hello There';
var isRad = true;

var groceries = ['Milk', 'Eggs', 'Cheese'];

document.getElementById('box').innerHTML = number+5;

if(number == 10) {
    console.log('Yeah buddy');
} else {
    console.log('Nope!');
}

for (var i=0; i < 10; i++) {
    console.log(i);
}

function listGroceries() {
    for (var i=0; i < groceries.length; i++) {
        console.log(groceries[i]);
    }
}

listGroceries();

document.getElementById('box').addEventListener('click', function() {
    alert('I got clicked');
});