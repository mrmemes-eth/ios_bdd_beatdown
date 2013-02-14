Then /^the "([^"]+)" label should have the text "([^"]+)"$/ do |mark,text|
  texts = frankly_map("label marked:'#{mark}'", 'text')
  texts.should have(1).entry
  texts.first.should eq(text)
end
