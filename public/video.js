(function() {
    var video = document.getElementById('video'),
        vendorUrl = window.URL || window.webkitURL;

    navigator.getMedia =    navigator.getUserMedia ||
                                navigator.webkitGetUserMedia ||
                                navigator.mozGetUserMedia ||
                                navigator.msGetUserMedia;

    //capiturando video
    navigator.getMedia({
        video: true,
        audio: false
    }, function (stream) {
        video.srcObject = stream;
        video.play();
    }, function(error){
        //error ocorreu
        console.log("Erro na camera");
    });
})();