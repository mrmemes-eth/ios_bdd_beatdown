Feature: uppercase some text

  Scenario: do it!
    Given I type "lower case string" into the "enter text" text field
    When I touch "uppercase it"
    Then the "outputLabel" label should have the text "LOWER CASE STRING"
