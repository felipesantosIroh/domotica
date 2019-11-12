 $("#luzSala").click(function(){
    const call = io();
    var button = $(this).val();
    console.log(button);
    call.emit('btnAction', {
        value: button.toString()
    });
    if ($(this).hasClass("btn-danger"))
        $(this).addClass("btn-success").removeClass("btn-danger");
    else
        $(this).addClass("btn-danger").removeClass("btn-success");
 });

 $("#luzQuarto").click(function(){
    const call = io();
    var button = $(this).val();
    console.log(button);
    call.emit('btnAction', {
        value: button.toString()
    });
    if ($(this).hasClass("btn-danger"))
        $(this).addClass("btn-success").removeClass("btn-danger");
    else
        $(this).addClass("btn-danger").removeClass("btn-success");    
 });

 $("#luzCozinha").click(function(){
    const call = io();
    var button = $(this).val();
    console.log(button);
    call.emit('btnAction', {
        value: button.toString()
    });
    if ($(this).hasClass("btn-danger"))
        $(this).addClass("btn-success").removeClass("btn-danger");
    else
        $(this).addClass("btn-danger").removeClass("btn-success");    
 });

 $("#luzGaragem").click(function(){
    const call = io();
    var button = $(this).val();
    console.log(button);
    call.emit('btnAction', {
        value: button.toString()
    });
    if ($(this).hasClass("btn-danger"))
        $(this).addClass("btn-success").removeClass("btn-danger");
    else
        $(this).addClass("btn-danger").removeClass("btn-success");
 });

 $("#luzBanheiro").click(function(){
    const call = io();
    var button = $(this).val();
    console.log(button);
    call.emit('btnAction', {
        value: button.toString()
    });
    if ($(this).hasClass("btn-danger"))
        $(this).addClass("btn-success").removeClass("btn-danger");
    else
        $(this).addClass("btn-danger").removeClass("btn-success");
 });

 $("#luzCorredor").click(function(){
    const call = io();
    var button = $(this).val();
    console.log(button);
    call.emit('btnAction', {
        value: button.toString()
    });
    if ($(this).hasClass("btn-danger"))
        $(this).addClass("btn-success").removeClass("btn-danger");
    else
        $(this).addClass("btn-danger").removeClass("btn-success");
 });