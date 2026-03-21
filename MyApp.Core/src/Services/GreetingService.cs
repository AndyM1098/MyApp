namespace MyApp.Core.Services;

/// <summary>
/// Service for greeting operations
/// </summary>
public class GreetingService
{
    public string SayHello(string name)
    {
        return $"Hello, {name}!";
    }

    public string GetGreeting(string name)
    {
        return $"Greetings, {name}!";
    }

    public string GetWelcome(string name)
    {
        return $"Welcome, {name}! We're glad to have you here.";
    }
}
