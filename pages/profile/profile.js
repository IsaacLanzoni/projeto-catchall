document.addEventListener("DOMContentLoaded", () => {
    searchUserData();
});

async function logout() {
    
    const {error} = await supabaseClient.auth.signOut();

    if(error){
        alert(`Erro ao fazer logout: ${error.message}`);
    } else {
        window.location.href = "../../forms/login/index.html";
    }
}

async function searchUserData(){

    const main = form.main();
    const username = form.username();
    const email = form.email(); 

    const {data: { user } } = await supabaseClient.auth.getUser();

    if(user){
        const {data, error} = await supabaseClient
            .from('profiles')
            .select('*')
            .eq('id', user.id)
            .single()
    
    
        if(error){
            console.log("Erro ao buscar informações do usuário: ", error);
        } else{
            username.innerText = data.name;
            email.innerText = user.email;
        }

        main.style.display = "block"

    }

    



}

function showSidebar(){
    const sidebar = window.document.querySelector('.sidebar');

    sidebar.style.display = 'flex';
}

function hideSidebar(){
    const sidebar = window.document.querySelector('.sidebar');

    sidebar.style.display = 'none';
}


const form = {
    profileImage: () => document.getElementsByClassName("profile-image")[0],
    email: () => document.getElementsByClassName("email-field")[0],
    username: () => document.getElementsByClassName("username")[0],
    main: () => document.querySelector("main"),
} 