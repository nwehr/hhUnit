### Build Docker Image
`docker build -t nunit ./`

### Run Container
`docker run --rm -t -v $(pwd)/test:/unit-tests nunit`