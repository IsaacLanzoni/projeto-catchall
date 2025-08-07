document.addEventListener('DOMContentLoaded', async () => {
      
  supabaseClient.auth.getSession().then(({ data: { session } }) => {
    if (!session) {
      window.location.href = '../../forms/login/index.html';
    }
  });


  supabaseClient.auth.onAuthStateChange((event, session) => {
    if (!session) {
      window.location.href = '../../forms/login/index.html';
    }
  });

});
