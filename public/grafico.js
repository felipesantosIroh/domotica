const socket = io();
let counter = 2;

socket.on('serial:data', function(dataSerial){
    console.log(dataSerial);
    myChart.data.labels.push(counter);
    myChart.data.datasets.forEach(dataset => {
        dataset.data.push(dataSerial.value);
    });
    counter = counter + 2;
    myChart.update();
});

socket.on('serial:data', function(dataSerial){
    console.log(dataSerial);
    myChart.data.labels.push(counter);
    myChart.data.datasets.forEach(dataset => {
        dataset.data.push(dataSerial.value);
    });
    counter = counter + 2;
    myChart2.update();
});

var ctx = document.getElementById('utGrafico').getContext('2d');
var myChart = new Chart(ctx, {
    type: 'line',
    data: {
        label:'Segundos',
        datasets: [{   
            label: 'Temperatura',
            fill: false,
            data: [],
            backgroundColor: [
                'rgba(0,0,255,0.3)'
            ],
            borderColor: [
                'rgba(0,0,255,1)'
            ]
        }]
},
    options: {
        scales: {
            yAxes: [{
                ticks: {
                    beginAtZero: true
                }
            }]
        }
    }
});

var ctx2 = document.getElementById('utGrafico2').getContext('2d');
var myChart2 = new Chart(ctx2, {
    type: 'line',
    data: {
        label:'Segundos',
        datasets: [{   
            label: 'Temperatura',
            fill: false,
            data: [],
            backgroundColor: [
                'rgba(0,0,255,0.3)'
            ],
            borderColor: [
                'rgba(0,0,255,1)'
            ]
        }]
},
    options: {
        scales: {
            yAxes: [{
                ticks: {
                    beginAtZero: true
                }
            }]
        }
    }
});