using Microsoft.AspNetCore.Mvc;
using MyApp.Core.Models;
using MyApp.Core.Services;

namespace MyApp.Web.Controllers;

/// <summary>
/// Home controller - demonstrates using Core services
/// </summary>
public class HomeController : Controller
{
    private readonly ILogger<HomeController> _logger;
    private readonly GreetingService _greetingService;

    public HomeController(ILogger<HomeController> logger)
    {
        _logger = logger;
        _greetingService = new GreetingService();
    }

    public IActionResult Index()
    {
        // Example: Use Core service
        var greeting = _greetingService.SayHello("User");
        ViewData["Greeting"] = greeting;

        // Example: Create Core model
        var user = new User
        {
            Id = 1,
            Name = "John Doe",
            Email = "john@example.com",
            City = "New York"
        };

        return View(user);
    }

    public IActionResult Greet(string name = "Guest")
    {
        if (string.IsNullOrEmpty(name))
            name = "Guest";

        var greeting = _greetingService.GetWelcome(name);
        ViewData["Message"] = greeting;

        return View();
    }

    public IActionResult Error()
    {
        return View();
    }
}
