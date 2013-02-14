Feature: Uppercasing

  Scenario: do it!
    Given I enter "lower case string" into the "enter text" input field
    When I touch the "uppercaseButton" button
    Then I should see "LOWER CASE STRING"
