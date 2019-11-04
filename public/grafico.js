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

var ctx = document.getElementById('utGrafico').getContext('2d');
var myChart = new Chart(ctx, {
    type: 'line',
    data: {
        label:'Segundos',
        datasets: [{
            label: 'Umidade',
            fill: false,
            data: [],
            backgroundColor: [
                'rgba(255, 99, 132, 0.2)',
            ],
            borderColor: [
                'rgba(255, 99, 132, 1)',
            ],
            borderWidth: 2
        },  {
        label: 'Temperatura',
        fill: false,
        backgroundColor:
        },
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