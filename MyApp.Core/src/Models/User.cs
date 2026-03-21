namespace MyApp.Core.Models;

/// <summary>
/// Represents a user in the application
/// </summary>
public class User
{
    public int Id { get; set; }
    public string Name { get; set; } = string.Empty;
    public string Email { get; set; } = string.Empty;
    public string? PhoneNumber { get; set; }
    public DateTime CreatedAt { get; set; } = DateTime.Now;
    public bool IsActive { get; set; } = true;
    public string? Address { get; set; }
    public string? City { get; set; }
    public string? Country { get; set; }

    /// <summary>
    /// Gets the user's full display name
    /// </summary>
    public string GetDisplayName()
    {
        return $"{Name} ({Email})";
    }

    /// <summary>
    /// Validates if the user has required information
    /// </summary>
    public bool IsValid()
    {
        return !string.IsNullOrEmpty(Name) && 
               !string.IsNullOrEmpty(Email) && 
               Id > 0;
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
    public void UpdateContactInfo(string email, string? phone = null)
    {
        Email = email;
        if (!string.IsNullOrEmpty(phone))
            PhoneNumber = phone;
    }
}
