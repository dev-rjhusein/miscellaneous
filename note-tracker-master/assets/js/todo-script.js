
//DELETE TODO   
$("#keeper").on("click",".trash", function(event){
    $(this).parent().fadeOut(250, function(){
        $(this).remove();
    });
    event.stopPropagation(); //Don't bubble events
})

//Toggle text input
$("#add-btn").on("click", function(){
    $("#text-entry").toggleClass("hide-element");
    $("#text-entry").val("");
})
//Add a todo by hitting "Enter"
$("#text-entry").on("keypress", function(e){
    if((e.keyCode == 13) && ($(this).val() != "")){
       addTodo($(this).val());
    }
})

//Check off todos by clicking
$("#keeper").on("click", ".todo", function(){
    $(this).toggleClass("completed");
})


function addTodo(newText){
    //Adding a todo to list
    $("#keeper").append('<li class="todo"><span class="trash"><i class="fa fa-trash"></i></span>' + newText + '</li>');

    $("#text-entry").val("");
}
