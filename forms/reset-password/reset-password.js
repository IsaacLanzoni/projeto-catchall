async function onClickResetButton(){
    const email = form.email().value;
    const timerAdvice = form.timerAdvice();
    const resetButton = form.resetButton();

    const {data, error} = await supabaseClient.auth.resetPasswordForEmail(email, 
        {
            redirectTo: 'https://isaaclanzoni.github.io/projeto-catchall/forms/recovery/recoverpassword.html'
        }
    );

    if(error){
        alert("Erro, email de verificação não foi enviado: ", error.message);
    } else{
        timerAdvice.style.display = "block";
        resetButton.disabled = true;
        emailTimerReset(resetButton, timerAdvice);
    }
}

function emailTimerReset(time, element){
    let timeLeft = 180;

    const interval = setInterval(() => {
        element.innerText = `Espere até poder enviar outro email: ${timeLeft} segundos`;
        timeLeft--;

        if(timeLeft <= 0){
            clearInterval(interval);
            element.innerText = '';
            time.disabled = false;
        }   
    }, 1000);
}

function onClickButton() {
    toggleEmailErrors();
}

document.addEventListener("DOMContentLoaded", function () {

    form.email().addEventListener("input", () => {
        toggleEmailErrors(); 
        toggleButtonsDisable(); 
    });

});


function onChangeEmail(){
    toggleEmailErrors();
    toggleButtonsDisable();
}


function toggleEmailErrors() {
    const email = form.email().value;

    form.emailRequiredError().style.display = email ? "none" : "block";
    form.emailInvalidError().style.display = validateEmail(email) ? "none" : "block";
}

function toggleButtonsDisable () {
    const email = form.email().value;
    const emailValid = isEmailValid();

    form.resetButton().disabled = !emailValid;

    form.resetButton().disabled = !emailValid;
}

function isEmailValid() {
    const email = form.email().value;
    if (!email){
        return false;
    }
    return validateEmail(email);
}


const form = {
    email: () => document.getElementById('reset-email-input'),
    resetButton: () => document.getElementById('reset-button'),
    emailInvalidError: () => document.getElementById('email-invalid-error'),       
    emailRequiredError: () => document.getElementById('email-required-error'),
    timerAdvice: () => document.getElementById("timer-advice"),
}