document.addEventListener("DOMContentLoaded", async () => {
    const url = new URL(window.location.href);
    const access_token = url.searchParams.get("access_token");
    const refresh_token = url.searchParams.get("refresh_token");
    const type = url.searchParams.get("type");

    if (type === "recovery" && access_token && refresh_token) {
        const { error } = await supabaseClient.auth.setSession({
            access_token,
            refresh_token
        });

        if (error) {
            alert("Erro ao restaurar sessão de recuperação.");
            console.error(error);
        } else {
            console.log("Sessão de recuperação iniciada com sucesso.");
        }
    }   
});
