namespace MyApp.Core.Models;

/// <summary>
/// Represents a Student in the Application
/// </summary>
public class Student
{
    public int StudentId { get; set; }
    public string Name { get; set; } = string.Empty;
    public string Email { get; set; } = string.Empty;
    public DateTime CreatedAt { get; set; } = DateTime.Now;
    public bool IsActive { get; set; } = true;

    /// <summary>
    /// Gets the user's full display name
    /// </summary>
    public string GetDisplayName()
    {
        return $"{Name}";
    }

    /// <summary>
    /// Validates if the user has required information
    /// </summary>
    public bool IsValid()
    {
        return !string.IsNullOrEmpty(Name) &&
               StudentId > 0;
    }

    /// <summary>
    /// Deactivates the user account
    /// </summary>
    public void Deactivate()
    {
        IsActive = false;
    }

    /// <summary>
    /// Reactivates the user account
    /// </summary>
    public void Activate()
    {
        IsActive = true;
    }

    /// <summary>
    /// Updates user contact information
    /// </summary>
    public void UpdateContactInfo(string email)
    {
        Email = email;
    }
}
