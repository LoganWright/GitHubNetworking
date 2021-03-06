//
//  GHAuth.h
//  GitIssues-iOS
//
//  Created by Logan Wright on 1/28/15.
//  Copyright (c) 2015 LowriDevs. All rights reserved.
//

#import <Foundation/Foundation.h>


// TODO: Make Constants
/*
 (no scope)	Grants read-only access to public information (includes public user profile info, public repository info, and gists)
 user	Grants read/write access to profile info only. Note that this scope includes user:email and user:follow.
 user:email	Grants read access to a user’s email addresses.
 user:follow	Grants access to follow or unfollow other users.
 public_repo	Grants read/write access to code, commit statuses, and deployment statuses for public repositories and organizations.
 repo	Grants read/write access to code, commit statuses, and deployment statuses for public and private repositories and organizations.
 repo_deployment	Grants access to deployment statuses for public and private repositories. This scope is only necessary to grant other users or services access to deployment statuses, without granting access to the code.
 repo:status	Grants read/write access to public and private repository commit statuses. This scope is only necessary to grant other users or services access to private repository commit statuses without granting access to the code.
 delete_repo	Grants access to delete adminable repositories.
 notifications	Grants read access to a user’s notifications. repo also provides this access.
 gist	Grants write access to gists.
 read:repo_hook	Grants read and ping access to hooks in public or private repositories.
 write:repo_hook	Grants read, write, and ping access to hooks in public or private repositories.
 admin:repo_hook	Grants read, write, ping, and delete access to hooks in public or private repositories.
 admin:org_hook	Grants read, write, ping, and delete access to organization hooks. Note: OAuth tokens will only be able to perform these actions on organization hooks which were created by the OAuth application. Personal access tokens will only be able to perform these actions on organization hooks created by a user.
 read:org	Read-only access to organization, teams, and membership.
 write:org	Publicize and unpublicize organization membership.
 admin:org	Fully manage organization, teams, and memberships.
 read:public_key	List and view details for public keys.
 write:public_key	Create, list, and view details for public keys.
 admin:public_key	Fully manage public keys.
 */

@class GHCredential;

@interface GHAuth : NSObject

#pragma mark - Configure

+ (void)configureGitHubAuthWithClientId:(NSString *)clientId
                           clientSecret:(NSString *)clientSecret
                            redirectURI:(NSString *)redirectURI
                              andScopes:(NSArray *)scopes;

#pragma mark - Request Authorization

+ (void)authorizeApplicationIfNecessaryWithCompletion:(void (^)(GHCredential *credential, NSError *error))completion;

#pragma mark - Respond to Callback

+ (BOOL)canHandleOpenUrl:(NSURL *)openUrl;
+ (void)handleOpenUrl:(NSURL *)openUrl;

#pragma mark - Current Credential

+ (GHCredential *)currentCredential;
+ (void)setCurrentCredential:(GHCredential *)credential;

@end
