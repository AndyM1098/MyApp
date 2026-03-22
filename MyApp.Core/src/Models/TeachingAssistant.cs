namespace MyApp.Core.Models;

/// <summary>
/// Represents a Teaching Assistant in the Application
/// </summary>
public class TeachingAssistant
{
    public int TeachingAssistantId { get; set; }
    public string Name { get; set; } = string.Empty;
    public string Email { get; set; } = string.Empty;
    public DateTime CreatedAt { get; set; } = DateTime.Now;
    public bool IsActive { get; set; } = true;

    /// <summary>
    /// Gets the TA's full display name
    /// </summary>
    public string GetDisplayName()
    {
        return $"{Name}";
    }

    /// <summary>
    /// Validates if the TA has required information
    /// </summary>
    public bool IsValid()
    {
        return !string.IsNullOrEmpty(Name) &&
               TeachingAssistantId > 0;
    }

    /// <summary>
    /// Deactivates the TA account
    /// </summary>
    public void Deactivate()
    {
        IsActive = false;
    }

    /// <summary>
    /// Reactivates the TA account
    /// </summary>
    public void Activate()
    {
        IsActive = true;
    }

    /// <summary>
    /// Updates TA contact information
    /// </summary>
    public void UpdateContactInfo(string email)
    {
        Email = email;
    }
}