// Build a web app host using command-line args and default ASP.NET Core configuration.
var builder = WebApplication.CreateBuilder(args);

// Register MVC services so controllers can return Razor views.
builder.Services.AddControllersWithViews();

// Build the app from configured services and settings.
var app = builder.Build();

// Configure middleware for incoming HTTP requests.
if (!app.Environment.IsDevelopment())
{
    // Route unhandled exceptions to a friendly error page in non-dev environments.
    app.UseExceptionHandler("/Home/Error");
    // Tell browsers to enforce HTTPS for future requests.
    app.UseHsts();
}

// Redirect HTTP requests to HTTPS.
app.UseHttpsRedirection();
// Serve static files from wwwroot (css, js, images, etc.).
app.UseStaticFiles();

// Enable endpoint routing so requests can be matched to controller actions.
app.UseRouting();

// Apply authorization checks before hitting mapped endpoints.
app.UseAuthorization();

// Define the default MVC route:
// /{controller}/{action}/{id?}
// Defaults to HomeController.Index when no route segments are provided.
app.MapControllerRoute(
    name: "default",
    pattern: "{controller=Home}/{action=Index}/{id?}");

// Start listening for requests.
app.Run();
