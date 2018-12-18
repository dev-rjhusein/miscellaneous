//Declare any objects to be used
const testArea = document.querySelector("#test-area");
let originText = document.querySelector("#origin-text p").innerHTML;
const resetButton = document.querySelector("#resetButton");
const theTimer = document.querySelector("#timer");
var parText = document.querySelector("#paragraph");

var timer = [0, 0, 0, 0];       //Minutes, Seconds, 1/100th of seconds, 1/1000th of seconds
var interval;
var timerRunning = false;

//Leading zero helper function
function leadingZero(time) {
    //add a "0" in front of numbers less than double digits
    if (time <= 9) {
        time = "0" + time;
    }
    return time;
}
//Spell check
function spellCheck(){
    let textEntered = testArea.value;
    let originTextMatch = originText.substring(0, textEntered.length);

    if(textEntered == originText){
        alert(w_p_m());
        testArea.style.borderColor = "rgb(50, 250, 100)";
        testArea.setAttribute("disabled","");
        clearInterval(interval);
    }
    else{
        if(textEntered == originTextMatch){
            testArea.style.borderColor = "rgb(50, 100, 250)";
        }
        else{
            testArea.style.borderColor = "rgb(250, 50, 50)";
        }
    }
}

function runTimer(){
    let currentTime = leadingZero(timer[0]) + ":" +
        leadingZero(timer[1]) + ":" + leadingZero(timer[2]);

    theTimer.innerHTML = currentTime;
    timer[3] += 1;

    timer[0] = Math.floor((timer[3]/100)/60);                                      //Minutes == Thousandth of seconds / 100 (-to seconds) / 60 (-to minutes)
    timer[1] = Math.floor((timer[3]/100) - (timer[0] * 60));                       //Seconds == Thousandth of seconds / 100 (-to second) - minutes * 60 (-to seconds)
    timer[2] = Math.floor(timer[3] - (timer[1] * 100) - (timer[0] * 6000));        //Hundreth seconds == [Thousandth of seconds] - [seconds * 100] - [minutes * 6000]
}

//Start the timer
function start(){
    let textEnteredLength = testArea.value.length;
    if (textEnteredLength === 0 && !timerRunning){
        timerRunning = true;
        interval = setInterval(runTimer, 10);
    }
}

//Reset timer and text
function reset() {
    clearInterval(interval);
    interval = null;
    timer = [0,0,0,0];
    timerRunning = false;
    testArea.style.borderColor = "rgb(150,150,150)";
    testArea.value = "";
    testArea.focus();
    testArea.removeAttribute("disabled", "");
    theTimer.innerHTML = "00:00:00";
    parText.innerHTML = get_paragraph(Math.floor(Math.random() * (parChoice.length - 1)));
    originText = (parText.textContent);

}


// Event Listeners
testArea.addEventListener("keypress", start);
testArea.addEventListener("keyup", spellCheck, false);
document.addEventListener("click", function(){theTimer.scrollIntoView();testArea.focus();});
resetButton.addEventListener("click", reset, false);

//words per minute ==
function w_p_m(){
    let time = (timer[3]/100)/60;
    let words = originText.split(" ").length;

    return Math.round((words / time), 2);

}



















const parChoice = [
    'A guilty advantage objects beside each sweat. The package believes in the director! Around a starring lunch barks the geographical needle. The alphabet interferes into any rainbow.',
    'A jumping circle accords the academic floor. When will the plaster stamp over the sophisticated box? Within any joy farms the beautiful propaganda. The joke prosecutes behind her protest.',
    "The young lesbian filters the down verse. Why can't the shape intervene? The ecology captures a rotate arch. The dissimilar liaison prevails within a tailor.",
    'A heaven sweeps above a conducted change. A linear contrast monkeys a wrecker. The pragmatic forum retracts beneath a card. The violate class exits past an alarming evil. A charm hails a naughty quantum.',
    'A leather waves around the scarf. Our hook accomplishes the defense. The deaf tips the jet on top of the shaky skeleton. The hypocrisy leans? A lump grows.',
    "Why won't the hired creature hope? A standing request poses. The bliss polices a mask. The cultural trail accepts around each room. The horrible composer conforms near the burden. Why can't the addressed dummy bow opposite the venture?",
    "Why can't a corn monitor the oil? A light rocks with the scenery! The flexible premise walks below the noble. The plus eyesight regards the looking success. How does the mature romance proceed? The half glove noses opposite the relative.",
    'The turntable counts. The weather tea progresses. A lesser nun finishes next to the nine disguise. Should the logical analogue chalk? The bulb communicates an automobile.',
    'The secretary sizes a breathing smoke. The countryside counts in the boat! The agent pinks a mob verse over a referendum. The image rivals the tome. My proportional cat frowns.',
    "The biblical damp struggles around a detected telephone. A suicide bundles the deal garden with a request. The blamed client beams near the disorder. Why can't another convinced treasure wing another compound?",
    "A chemistry errs around the conduct. When can the creep polish the creed? Beside the driver bubbles the frank cousin. The unknown coughs? Why won't every ageing era read?",
     "A murderer cautions the huge referendum. Why can't the won table reckon? A pornography horns the courage next to a through retrieval. A supreme drip sails the colleague. Will the exempt engine succeed on top of the consent?",
    'How does the middle prototype frighten a stringent correspondence? The earth summarizes a cider. When will the weak liaison shine before a squeeze? Why does a calm killer locate the professional? Why does the freedom bicycle? Within the north native starves an adequate outline.',
    'The graffito accommodates a gnome. The burst dresses before the attacking trend. The singer generalizes the rail. The bush swings under the union! A rocket stirs? The adequate eagle contents a nasty quota.',
    'The horrendous horror bays inside a portrayed viewer. How can a spoof yawn near your decreasing pulp? How does an umbrella cry? Will the crush chalk without the rusty idea?', 
    'The priced drum chooses across the hospital. A young finishes against the patched stream. Without whatever grouped alternative jams the fat tour. The contrived beginner accepts above the extraordinary bicycle.',
    'Every lyric explodes our enemy. The broke hardship freezes the father. How will a mere nick suspect a burden? An abstract smoker toes the line. The orbit degenerates with the in sunlight. The ballet gowns a contempt.', 
    'A wooden food foams against the cultural medium. The marked guy reigns. This ritual festival reaches. Should a successor equip the full bigotry?', 
    'The sloppy purchase screams without the oral incompetence. Every intercourse inserts a sealed libel on top of the cabbage. The questionable photocopy tables a hypocrisy above a connected existence. The major battles the bias.',
    'The looking constitutional entitles the worm behind a shaped institute. The fluid feat sprays an unconscious with the nastiest nature. Into the physicist breaks an inflexible microprocessor. The sixty curtain rules.',
    'The imposing kid burdens the condemned burst. The connector breathes outside the paper! The atom reaches in the coming touch. How can the war privilege your gulf?', 
    'The clipping atmosphere rests upon each beast. An aging unknown succeeds. The debt confines an attractive aged. The fuse inherits the opened silence.',
    'A returning harmony spends the outset on top of the even manufacturer. A structural officer bicycles near the genocide. The ruin harms a biased weasel. A scratch arrests the frog.',
    'A human explodes. The penguin worships the superficial enterprise into the screen. The sundry slights a change. The companion outcries a salt. Why does the boat click?', 
    'A clarifying thumb emerges into our changed rear. Beneath the content sentence leaps the intervening terror. A philosophical recruit yawns on top of an outline. The exotic table eggs the calculated class.', 
    'The destined warp attends beneath the gut. The winter graduates! A critic veins the pursued panel on top of the approach. How can the suspect banana idle another helicopter?', 
    'The strength complains. Without the gift expands an arcane game. The sleeping reactionary flowers around the mad magic. The every male defeats the contentious origin. The kitchen shoes the breath.', 
    'The improbable prerequisite watches a group. The planetary violence scratches next to the successive sketch. The twenty banana blankets my colored turnround. A phoenix marches!', 
    'A rash medicine conceals a cotton around a reliable garden. Your token squeezes a riot. A kid axes a fundamental trash. A religion destines the intimate past the unsure etymology.', 
    'Another persecuted asset obtains the indirect apathy. Outside the synthesis stirs the punch. The wrapped desert breaks on top of the passage. The stereo motors her bedroom.', 
    'How can the playground expense each thinking candidate? Before the defeated riots his negative. A reporter overcomes beneath any writer. The drip pulses into another talent. The parody smiles inside the diesel. The deaf expands under the autumn.', 
    "The inquiring grief pretends with its tray. The advice runs the shape. Each cardboard saint consults the box underneath an exhausted defect. Why won't the lager quibble? Any screaming secret pinks a penny fossil.",
    'A glance snacks? Why does the dressed human march near the airport? The blade glows before the reminder. A laughter responds. The answer escapes against the directive!', 
    'A socialist rages over our routine scotch. Does whatever furniture lie? Every requisite punch riots beneath the participant wrapper. A straw bicycles before the outstanding well. The release rests upon a heat.', 
    'Why does the shutdown pump? A dash pretends under the philosopher. A literature chairs a murder opposite the meaning look. The jerk represents the person under a minus number. How can the waking weekday trek into each battle? When can the jet mistake pile the relative bath?', 
    'Every explicit advice overflows against the brother arcade. The vicar invests in whatever fired sweat. The barred lawn stumbles across the agent. The tile arrests the linguistic shell.',
    "The basket fries the global nail beside the light. The whim nests near the understanding door. A salt sniff pats a cricket. Why won't the further ladder run another reverse myth? The published coal piles the minimum gasp.",
    'Can a cousin dislike each allergic passport? How can the rear encounter the greater crystal? The deserving monkey reinstates the jet. Your bean stimulates a less bread over the rail. The freak witches an acting counterpart. Whatever captain counts throughout the panic.',
    'The breeding peer overlaps outside its dive. The scroll refines the homosexual universe. The helicopter waves! A crude conservative prejudices the congested microprocessor.', 
    'Each pulled transcript presses against an unclear treat. A passport dips another rarest melody inside a spur. A damp vet rewrites the consultant. A patent church distributes a tasteless resident.',
    'A defeated buttons the ended gas. The wash paces opposite a nuts unseen. A beginner maps our harden near a concealed genocide. The phenomenon serves a counsel. The instructed intellectual prostitutes a bright tongue.',
    'A journalist courses a shorthand after the worth task. Can the treat prostitute another general? The unread nail cheats over any actual oil. The anniversary dashes before the multiplied bookshop. The advertised cuckoo duplicates the prototype near a pretend insistence. The compound interference chases an analysis.', 
    'The compatible decade terrifies a hail under a favorable clique. Our dubious crush objects over a theoretical ray. The synthesis persists on top of each forgotten tutorial. Will the cabbage piece the generous pot?', 
    'An artificial slot cultures a critical color. The major pains the unusual handful on top of a rot. A confidence bothers a drying wood. The shed priest argues in a painless brain.', 
    "The thankful pope pinks a likelihood. The silver missions a crunched rumor. Why won't the constant tennis sicken underneath the autobiography? The strangest shareholder differentiates the freak below a pseudo shutdown.", 
    'A group rod wants a liquor past the deprived dragon. A freedom halves the earned libel. The blade struggles near the manner. The airport defends a key.', 
    'Why does the shelter object? The finest appeal speaks beneath this stark signature. The shutdown stimulates the formula within the honored percentage. Should the benefit boggle in the aesthetic chain? The piece tenders any breakfast. The corridor forbids the hexadecimal sport.', 
    'A deep manufacturer finishes on top of a distinguished planet. The capital burst blows a postage. With a sect composes a mist. Under the requisite idiom leaks the embarrassing scientist'];
    
    function get_paragraph(x){
        return parChoice[x];
    }